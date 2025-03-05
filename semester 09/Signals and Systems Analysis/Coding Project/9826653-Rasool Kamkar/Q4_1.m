n = -100:100; % samples
w = 0.25; % Frequency

% Original signal
x = cos(w*n);

% Add AWGN to the signal
snr = 5; % Signal-to-Noise Ratio
y = awgn(x, snr, 'measured'); % Add noise
    

% Apply the filter to the noisy signal
y_filtered = filter(Hd, y);

% calculate fft of three signals
without_noise_fft = fft(x);
noisy_fft = fft(y);
filtered_fft = fft(y_filtered);



% Plot the filtered signal
figure(1);
subplot(3,2,1);
plot(n, x, LineWidth=1.5);
title('Original Signal x[n] = cos(wn)');
xlabel('n');
ylabel('x[n]');
grid on;

subplot(3,2,3);
plot(n, y, LineWidth=1.5);
title('Noisy Signal y[n]');
xlabel('n');
ylabel('y[n]');
grid on;

subplot(3,2,5);
plot(n, y_filtered, LineWidth=1.5);
title('Filtered Signal');
xlabel('n');
ylabel('filtered[n]');
grid on;

% plotting fft of three signals
subplot(3,2,2);
plot(n,abs(without_noise_fft),color='red');
title('FFT of cosine');
grid on;

subplot(3,2,4);
plot(n,abs(noisy_fft),color='red');
title('FFT of noisy cosine');
grid on;

subplot(3,2,6);
plot(n,abs(filtered_fft),color='red');
title('FFT of filtered cosine');
grid on;


