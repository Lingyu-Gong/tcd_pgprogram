# Audio Restoration Project

## Overview
This project focuses on audio restoration using median and cubic spline filtering techniques. The script processes a degraded audio file by eliminating clicks and restoring its quality. It compares the efficiency of median and cubic spline methods in terms of Mean Squared Error (MSE) and execution time.
<!-- - median filtering
- cubic splines -->

---

## Installation

To run this script, you need Python installed on your system along with the following libraries:
- NumPy

- SciPy

- Matplotlib

- tqdm
```sh
pip install numpy scipy matplotlib tqdm
```
---
## Usage
1. **Set Up:** Place your clean and degraded .wav files in the appropriate directory.  

2. **Running the Script:** Execute Assignment2_main.py. You will be prompted to input the window size for the filters.  

3. **Output:** The script will generate visualizations of the clean, degraded, restored (median filter), and restored (cubic spline filter) audio. It also outputs the MSE scores and execution times for both methods.  

---
## Testing
The script includes a test suite for the median calculation function. To run the tests, simply execute the script. Ensure you have the unittest module installed.

---
## Results

1. The image displays four separate waveforms, each representing different states of an audio file as visualized through a sound editing or analysis software. The waveforms are shown in a vertical sequence with the following labels: Clean Audio, Degraded Audio, Restored Audio Using Median Filter, Restored Audio Using Cubic Filter.

![Fig_result](https://github.com/Lingyu-Gong/tcd_pgprogram/blob/main/55c22ComputationalMethod/Assignment2/Fig_result.png)

2. Data comparison

Method | MSE score | Execution Time |
---------|-----------|----------------|
Median Filter| 0.0041 | 0.0070 |
Cubic Filter| 0.0041 | 0.0100 |

---
## Contact

For any queries, please contact gongl@tcd.ie.






<!-- For more details check [here](https://github.com/bndr/pipreqs)


Afer installing all required packages you can run the demo file simply by typing:
```sh
python demo_audio_restoration.py
```
--- -->
