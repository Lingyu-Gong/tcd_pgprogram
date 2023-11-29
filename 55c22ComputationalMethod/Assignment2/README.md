# Audio Restoration Project

## Overview
This project applies median and cubic spline filtering techniques for audio restoration. The provided Python script processes a degraded audio file, eliminating noise artifacts and restoring its quality. It assesses the performance of both methods by comparing Mean Squared Error (MSE) and execution time.

## Installation

Ensure you have Python installed on your system. Install the required libraries using the following commands:

- NumPy:
```sh
pip install numpy
```
- SciPy:
```sh
pip install scipy
```
- Matplotlib:
```sh
pip install matplotlib
```
- tqdm:
```sh
pip install tqdm
```
- playsound (if you encounter issues, upgrade `setuptools` and `wheel` before installing):
```sh
pip install --upgrade setuptools wheel
pip install playsound
```
## Usage
1. **Setup:** Store your clean and degraded .wav files in the designated directory.
2. **Execution:** Run `Assignment2_main.py` in your terminal and input the window size for the filters when prompted.
3. **Output:** The script generates visualizations of the original, degraded, and restored audio. It provides MSE scores and execution times for median and cubic spline filters.

## Testing
The script includes unit tests for the median calculation using the `unittest` framework. Run the script to execute these tests.

## Results

### Visualizations
The script outputs waveform visualizations for each stage of the audio processing:
- Clean Audio
- Degraded Audio
- Restored Audio Using Median Filter
- Restored Audio Using Cubic Filter

![Audio Restoration Results](https://github.com/Lingyu-Gong/tcd_pgprogram/blob/main/55c22ComputationalMethod/Assignment2/Fig_result.png)

### Performance Metrics
The performance of the median and cubic spline filters is summarized as follows:

| Method          | MSE Score | Execution Time |
|-----------------|-----------|----------------|
| Median Filter   | 0.0041    | 0.0070 seconds |
| Cubic Filter    | 0.0041    | 0.0100 seconds |

The MSE scores are identical, suggesting comparable accuracy, but the median filter boasts a faster execution time.

## Contact
For any questions or further information, please reach out to gongl@tcd.ie.

