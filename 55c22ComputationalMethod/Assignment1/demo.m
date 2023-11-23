clc ;clear all; close all;

% initialize eveything
block_size = 1000 ;
duration_length = 10 ;
fs_req = 8000 ;
restored_final = zeros(1, 1) ;
% import the original audio
[clean_audio, fs_clean] = audioread('clean.wav') ;
[degraded_audio, fs_degraded] = audioread('degraded.wav') ;
original_size = length(degraded_audio) ;
circle = original_size / block_size ;

%===============================================================%
% show the original clean and degraded data as figure1
% TIME DOMAIN
figure(1) ;

t_clean = (1/fs_clean)*(0: numel(clean_audio) - 1);
subplot(2,3,1) ;
plot(t_clean, clean_audio) ;
title('Time: clean audio') ;
xlabel('Time(t)') ;
ylabel('Amplitude(dB)') ;
grid on ;

t_degraded = (1/fs_degraded)*(0: numel(degraded_audio) - 1);
subplot(2,3,2) ;
plot(t_degraded, degraded_audio) ;
title('Time: degraded audio') ;
xlabel('Time(t)') ;
ylabel('Amplitude(dB)') ;
grid on ;

% FREQUENCY DOMAIN
clean_fft = fft(clean_audio, original_size) ;
clean_fft_time = (0: original_size-1)/ fs_clean ;
subplot(2,3,4) ;
plot(clean_fft_time, clean_fft) ;
title('Frequency: clean audio') ;
xlabel('Time(t)') ;
ylabel('Frequency(Hz)') ;

degraded_fft = fft(degraded_audio, original_size) ;
degraded_fft_time = (0: original_size-1)/ fs_degraded ;
subplot(2,3,5) ;
plot(degraded_fft_time, degraded_fft) ;
title('Frequency: degraded audio') ;
xlabel('Time(t)') ;
ylabel('Frequency(Hz)') ;

%===============================================================%
missing_store = [] ;
click_data = zeros(length(degraded_audio),1) ;
degraded = abs(degraded_audio) ;
click_data(find((degraded == 0.5) | (degraded>= 0.99))) = 1 ;
click_num = length(find((degraded == 0.5) | (degraded>= 0.99))) ; 
fprintf('The original number of clicks is %6.0f\n', click_num) ;
figure(2) ;
subplot(2,1,1) ;
plot(click_data) ;
title("The original clicks in the audio") ;

% csvwrite('myFile.txt',click_data,1,134)
dlmwrite('bk.txt', click_data, 'delimiter',' ')  ;
%===============================================================%
for i = 1: circle
    % for every block
    % calculate coefficients
    start_index = (i-1)* block_size+ 1 ;
    end_index = start_index+ block_size- 1 ;
    degraded_block = (degraded_audio(start_index: end_index)) ;
    model_order = 3;
    [coeffs, avg1] = estimateARcoeffs(degraded_block, model_order);

    % calculate residual
    avg = mean(degraded_block) ;
    data = degraded_block- avg ;
    res = getResidual(data, coeffs) ;
    
    % threshold
    threshold = 0.4 ;
    degraded_block(abs(res) >= threshold) = 0 ; 
    
    % interpolates the missing data
    detected_missing = zeros(block_size, 1) ;
    % when data = 0 ; detected = 1 ;
    detected_missing(find(abs(res) >= threshold)) = 1 ;
    missing_store = [missing_store; detected_missing] ;
    [restored2, Ak2, Au2, yk2] = interpolateAR(degraded_block, detected_missing, coeffs);
    % combine together
    restored_final = [restored_final; restored2] ;
end
    figure(2) ;
    subplot(2,1,2) ;
    plot(missing_store) ;
    detec_num = length(missing_store(find(missing_store== 1))) ;
    fprintf('The detected number of clicks is %6.0f\n', detec_num) ;
    title("The detected clicks in the audio") ;
%===============================================================%

restored_final = restored_final(2: end) ;
audiowrite("output.wav", restored_final, fs_req) ;
[restored_audio, fs_restored] = audioread("output.wav");
% calculate MSE
for i = 1: length(fs_req)
    mse = (degraded_audio(1:fs_restored)- restored_audio(1:fs_restored)).^2 ;
    mse = sum(mse) ;
end
mse_value = mse/ click_num ;
fprintf('The MSE is %6.3f\n', mse_value) ;

%===============================================================%
% show the data changes in restored_audio in figure 1
original_size = fs_restored;

figure(1) ;
t_after = (1/fs_restored)*(0: numel(restored_audio) - 1);
subplot(2,3,3) ;
plot(restored_audio) ;
title('Time: restored Audio') ;
xlabel('Time(t)') ;
ylabel('Amplitude(dB)') ;
grid on ;

restored_fft = fft(restored_audio, original_size) ;
restored_fft_time = (0: original_size-1)/ fs_restored ;
subplot(2,3,6) ;
plot(restored_fft_time, restored_fft) ;
title('Frequency: restored audio') ;
xlabel('Time(t)') ;
ylabel('Frequency(Hz)') ;

%===============================================================%
% combine audio
start_time = 1 ;
end_time = 6 ;
degraded = degraded_audio((start_time*fs_req: end_time*fs_req), 1) ;
restored = restored_audio((start_time*fs_req: end_time*fs_req), 1) ;
new_audio = [degraded; restored] ;
% test sound
sound(new_audio) ;
audiowrite("new_audio.wav", new_audio, fs_req) ;
% test sound
% sound(clean_audio) ;
% pause(15) ;
% sound(degraded_audio) ;
% pause(15) ;
% sound(restored_audio) ;
% pause(15) ;
