%% Part 1 : loading and plotting wav files
figure(1);


% Load the original .wav file
[file1, fs1] = audioread('Original.wav');
% Create a time vector
t1 = (0:length(file1) - 1) / fs1;

% Load the distorted .wav file
[file2, fs2] = audioread('Distorted.wav');
% Create a time vector
t2 = (0:length(file2) - 1) / fs2;

% Plot  Original.wav file
subplot(2, 2, 1);
plot(t1, file1);
title('Waveform of Original.wav');
xlabel('Time (s)');
ylabel('Amplitude');

% Plot  Distorted.wav file
subplot(2, 2, 3);
plot(t2, file2);
title('Waveform of Distorted.wav');
xlabel('Time (s)');
ylabel('Amplitude');


% Plotting FFT of both files
% calculate FFT of original.wav
fft_file1 = fft(file1);
L1 = length(file1);
% Calculate the spectrum 
P21 = abs(fft_file1/L1);
P11 = P21(1:L1/2+1);
P11(2:end-1) = 2*P11(2:end-1);

% calculate FFT of distorted.wav
fft_file2 = fft(file2);
L2 = length(file2);
% Calculate the spectrum
P22 = abs(fft_file2/L2);
P12 = P22(1:L2/2+1);
P12(2:end-1) = 2*P12(2:end-1);

% Create a frequency vector
f1 = fs1*(0:(L1/2))/L1;
f2 = fs2*(0:(L2/2))/L2;

% Plot the spectrum of the first file
subplot(2,2,2);
plot(f1, P11)
title('Spectrum of Original.wav');
xlabel('Frequency (f)');

% Plot the single-sided amplitude spectrum of the second file
subplot(2,2,4);
plot(f2, P12)
title('Spectrum of Distorted.wav');
xlabel('Frequency (f)');



%% Part 2 : caluclate and plot MSE
% Calculate the Mean Squared Error (MSE)
mse = mean((file1 - file2).^2);

% Display the MSE
disp(['The Mean Squared Error (MSE) between the two audio files is: ', num2str(mse)]);


%% Part 3 : Filtering the noise

% using lowpass filter to remove anything above 6000Hz
filtered_audio = lowpass(file2,5750,fs2);
% Save filtered audio in Recovered.wav
audiowrite('Recovered.wav',filtered_audio,fs2);

%% Part 4 : calculate MSE between Recovered and Original files
% calculate MSE
mse2 = mean((file1 - filtered_audio).^2);
% Display MSE
disp(['New MSE after filtering the noise is: ', num2str(mse2)]);