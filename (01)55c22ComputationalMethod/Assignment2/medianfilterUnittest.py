import numpy as np
import unittest

def calculate_med_num(input_data, window_size):
    """
    Calculate the moving median of a sequence of numbers.

    Args:
        input_data (str): A string of integers separated by spaces
        window_size (int): The size of window. Must be a positive integer.

    Returns:
        list: A list of medians for each window position.
    """
    num = [int(n) for n in input_data.split()]
    length_padding = (window_size-1)/ 2
    padding = [0] * int(length_padding)
    num = padding + num + padding

    # design median function
    len_input_data = len(num)
    median_arr = []
    reorder_arr = []

    for i in range(len_input_data):
        if(i+window_size <= len_input_data):
            # in order
            reorder_arr = num[i: i+window_size]
            reorder_arr.sort()
            if(window_size % 2 == 0): # if even
                mid_num = (reorder_arr[window_size//2]+ reorder_arr[window_size//2- 1])/ 2
                median_arr.append(mid_num)
            elif (window_size % 2 == 1): # if odd
                mid_num = reorder_arr[window_size//2]
                median_arr.append(mid_num)
    
    return median_arr


input_data = input("Plz input your data ")
window_size = int(input("Plz input your window size "))
median_arr = calculate_med_num(input_data, window_size)
print("Result:", median_arr)


class TestMedianArrayFunction(unittest.TestCase):
    def test_odd_window_size(self):
        input_data = "1 2 3 4 5"
        window_size = 3
        expected_output = [1, 2, 3, 4, 4]
        self.assertEqual(calculate_med_num(input_data, window_size), expected_output)

    def test_even_window_size(self):
        input_data = "1 2 3 4 5 6"
        window_size = 4
        expected_output = [1.5, 2.5, 3.5, 4.5, 4.5]
        self.assertEqual(calculate_med_num(input_data, window_size), expected_output)

    def test_single_element(self):
        input_data = "5"
        window_size = 1
        expected_output = [5]
        self.assertEqual(calculate_med_num(input_data, window_size), expected_output)

    def test_empty_input(self):
        input_data = ""
        window_size = 3
        expected_output = []
        self.assertEqual(calculate_med_num(input_data, window_size), expected_output)

if __name__ == '__main__':
    unittest.main()