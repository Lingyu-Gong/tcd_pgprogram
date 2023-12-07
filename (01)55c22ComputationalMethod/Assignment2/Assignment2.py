#Assignment2_main.py

import numpy as np
import unittest
import scipy.io.wavfile as wav
import matplotlib.pyplot as plt
from tqdm import tqdm
from scipy.interpolate import CubicSpline
import time
from playsound import playsound

# import data
## input window size
window_size = int(input("Please input your window size: "))
## read audio file
fs, audio_clean = wav.read('C:/GONG/pgprogram/tcd_pgprogram/55c22ComputationalMethod/Assignment2/clean.wav')
fs, audio_degraded = wav.read('C:/GONG/pgprogram/tcd_pgprogram/55c22ComputationalMethod/Assignment2/degraded.wav')
#print(fs)
audio_clean = audio_clean / 32678
audio_clean = audio_clean / 2
audio_degraded = audio_degraded / 32678
#----------------------------------Vitualization----------------------------------------#
## show input audio
fig = plt.figure()
ax1 = fig.add_subplot(4, 1, 1)
ax2 = fig.add_subplot(4, 1, 2)
ax3 = fig.add_subplot(4, 1, 3)
ax4 = fig.add_subplot(4, 1, 4)

ax1.plot(audio_clean)
ax1.set_title('Clean Audio', fontdict={'size': 10})
ax1.set_xlabel('Time')
ax1.set_ylabel('Amplitude')
ax1.tick_params(axis='both', labelsize=8)

ax2.plot(audio_degraded)
ax2.set_title('Degraded Audio', fontdict={'size': 10})
ax2.set_xlabel('Time')
ax2.set_ylabel('Amplitude')
ax2.tick_params(axis='both', labelsize=8)


# check wether is odd or not
def check_odd_filterlen(window_size):
    """
    Checks if the provided window size is an odd number.

    Args:
        window_size (Iterable or int): The size of the window to be checked.

    Raises:
        ValueError: If the window size is not odd, a ValueError is raised with an appropriate error message to indicate that the window size must be odd.
    """
    if(len(window_size)% 2 == 1):
        print("The window length can works, please keep going.")
    else:
        raise ValueError("Error: The window size is not odd.")

click_doc = np.loadtxt("C:/GONG/pgprogram/tcd_pgprogram/55c22ComputationalMethod/Assignment2/bk.txt")

# Find the position
click_pos = np.where(click_doc == 1)
click_pos_len = np.shape(click_pos)
print('The number of clicks in your audio: ', click_pos_len[1])

# Median Filter
audio_len = len(audio_degraded)
#print(audio_len)

def calculate_med_num(input_data, window_size):
    """
    Calculate the moving median of a sequence of numbers.

    Args:
        input_data (str): A string of integers separated by spaces
        window_size (int): The size of window. Must be a positive integer.

    Returns:
        list: A list of medians for each window position.
    """
    # design median function
    len_input_data = len(input_data)
    reorder_arr = np.array(window_size)

    for i in range(len_input_data):
        if(i+ window_size <= len_input_data):
            # in order
            reorder_arr = input_data[i: i+window_size]
            reorder_arr = list(reorder_arr)
            reorder_arr.sort()
            mid_num = reorder_arr[window_size//2]
    
    return mid_num

def calculate_mse(actual, predicted):
    """Calculate Mean Squared Error between actual and predicted values.

    Args:
        actual (array): Array of actual values.
        predicted (array): Array of predicted values.

    Returns:
        float: Mean Squared Error.
    """
    # Calculate MSE
    mse = np.mean((actual - predicted) ** 2)
    return mse

def cubic_spline_filter(block, x_points, y_points):
    """
    Apply cubic spline filter to a block of audio data.

    Args:
        block (np.array): The array of points to be interpolated.
        x_points (np.array): The x-coordinates of the data points.
        y_points (np.array): The y-coordinates of the data points.

    Returns:
        np.array: The interpolated values.
    """
    cubic_spline = CubicSpline(x_points, y_points)
    return cubic_spline(block)

#-------------------------------Eliminate the clicks----------------------------------------#
median_execution_start = time.time()

for i in tqdm(click_pos[0], desc="Processing clicks with median filter"):
    block_size = int((window_size-1)/ 2)
    block = audio_degraded[i- block_size: i+ block_size+ 1]
    mid_num = calculate_med_num(block, window_size) # get the restored data
    audio_degraded[i] = mid_num

median_execution_end = time.time()
median_execution_time = median_execution_end - median_execution_start

audio_restored_Median = wav.write("C:/GONG/pgprogram/tcd_pgprogram/55c22ComputationalMethod/Assignment2/Restored_Median.wav", fs, audio_degraded)

fs, audio_restored_Median = wav.read('C:/GONG/pgprogram/tcd_pgprogram/55c22ComputationalMethod/Assignment2/Restored_Median.wav')
ax3.plot(audio_restored_Median)
ax3.set_title('Restored Audio Using Median Filter', fontdict={'size': 10})
ax3.set_xlabel('Time')
ax3.set_ylabel('Amplitude')
ax3.tick_params(axis='both', labelsize=8)


cubic_execution_start = time.time()
for i in tqdm(click_pos[0], desc="Processing clicks with cubic splines"):
    block_size = int((window_size-1)/ 2)
    block = np.arange(i - block_size, i + block_size + 1)
    y_points = audio_degraded[i - block_size: i + block_size + 1]
    interpolated_values = cubic_spline_filter(block, block, y_points)
    audio_degraded[i] = interpolated_values[block_size]

cubic_execution_end = time.time()
cubic_execution_time = cubic_execution_end - cubic_execution_start

audio_restored_cubic = wav.write("C:/GONG/pgprogram/tcd_pgprogram/55c22ComputationalMethod/Assignment2/Restored_Cubic.wav", fs, audio_degraded)

fs, audio_restored_cubic = wav.read('C:/GONG/pgprogram/tcd_pgprogram/55c22ComputationalMethod/Assignment2/Restored_Cubic.wav')
ax4.plot(audio_restored_cubic)
ax4.set_title('Restored Audio Using Cubic Filter', fontdict={'size': 10})
ax4.set_xlabel('Time')
ax4.set_ylabel('Amplitude')
ax4.tick_params(axis='both', labelsize=8)

plt.tight_layout()
plt.show()

#---------------------------------------Calculate MSE----------------------------------------#

mse_score1 = calculate_mse(audio_clean[click_pos[0]], audio_restored_Median[click_pos[0]])            
print("Median Filter MSE score: ", mse_score1)

mse_score2 = calculate_mse(audio_clean[click_pos[0]], audio_restored_cubic[click_pos[0]])            
print("Cubic Filter MSE score: ", mse_score2)

#--------------------------------Calculate Execution Time------------------------------------#

print("Median Filter Execution Time: ", median_execution_time)
print("Cubic Spline Fliter Execution Time: ", cubic_execution_time)


# Function to play sound with error handling
def play_sound(file_path):
    try:
        playsound(file_path)
    except Exception as e:
        print(f"Error occurred while playing sound: {e}")

#-------------------------------------Play the music-----------------------------------------#

play_sound('C:/GONG/pgprogram/tcd_pgprogram/55c22ComputationalMethod/Assignment2/Restored_Median.wav')
time.sleep(10)
play_sound('C:/GONG/pgprogram/tcd_pgprogram/55c22ComputationalMethod/Assignment2/Restored_Cubic.wav')


class TestAudioProcessing(unittest.TestCase):

    def test_calculate_med_num(self):
        # Example test for calculate_med_num
        data = np.array([1, 2, 3, 4, 5])
        window_size = 3
        expected_median = 4
        result = calculate_med_num(data, window_size)
        self.assertEqual(result, expected_median, "The median calculation is incorrect")

if __name__ == '__main__':
    unittest.main()