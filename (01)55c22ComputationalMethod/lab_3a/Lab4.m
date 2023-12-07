clear ;
clc ;

% import audio 
[x, Fs] = audioread('speech_12.wav') ;
figure ;
subplot(4,1,1) ;
plot(x) ;
title('Original graphic');
xlabel('Frequency(Hz)') ;
ylabel('|X(f)|') ;
% If you want to try original one uncomment this
%sound(x, Fs) ;

% fast fourier transform TO frequency
nfft = 2^ 10 ;
X = fft(x, nfft) ;
fstep = Fs/nfft ;
fvec = fstep*(0: nfft/2-1) ;
fresp = 2* abs(X(1:nfft/2)) ;
subplot(4,1,2) ;
plot(fvec, fresp) ;
title('Single-Sided Amplitude Spectrum of x(t)') ;
xlabel('Frequency(Hz)') ;
ylabel('|X(f)|') ;

% find the max value
for i = 1: length(fvec)
    [find_data, find_data_index] = max(fresp) ;
end
% display the 
disp(find_data) ;
disp(fvec(find_data_index)) ;

% estimate the noise
Hd = FIRfilter;
estimate_audio= filter(Hd, x) ;

subplot(4,1,3) ;
plot(estimate_audio) ;
title('After Esitimation Audio');
xlabel('Frequency(Hz)') ;
ylabel('|X(f)|') ;

% re display the new one
nfft = 2^ 10 ;
esi_X = fft(estimate_audio, nfft) ;
esi_fstep = Fs/nfft ;
esi_fvec = esi_fstep*(0: nfft/2-1) ;
esi_fresp = 2* abs(esi_X(1:nfft/2)) ;
subplot(4,1,4) ;
plot(esi_fvec, esi_fresp) ;
title('After Esitimation Frequency') ;
xlabel('Frequency(Hz)') ;
ylabel('|X(f)|') ;

% find the max value
for i = 1: length(esi_fvec)
    [esi_find_data, esi_find_data_index] = max(esi_fresp) ;
end
% display the signal after
disp(esi_find_data) ;
disp(esi_fvec(esi_find_data_index)) ;

sound(estimate_audio, Fs) ;
