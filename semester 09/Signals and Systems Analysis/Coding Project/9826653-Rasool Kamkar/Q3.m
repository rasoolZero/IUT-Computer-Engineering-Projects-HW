%% Part 1: fourier series with N = 8 and N = 16

% Parameters
f = 0.5;                % Frequency of the square wave
T = 1 / f;            % Period of the square wave
N1 = 8;               % Number of terms in the Fourier series
N2 = 16;
t = -2*T:0.001:2*T;      % Time vector

% Generate a square wave signal
x = (square(2*pi*f*t)./2+0.5);

% Initialize the Fourier series approximation (set to a0)
x_fs1 = zeros(size(t))+(sum(x)/length(t));
x_fs2 = zeros(size(t))+(sum(x)/length(t));

% Calculate the Fourier series
for n = 1:2:N1  % Only odd harmonics contribute to a square wave
    x_fs1 = x_fs1 + 2/(n*pi) * sin(2 * pi * n * f * t);
end

for n = 1:2:N2
    x_fs2 = x_fs2 + 2/(n*pi) * sin(2 * pi * n * f * t);
end

% Plot the square wave and its Fourier series
figure(1);

% plot N = 8
subplot(2,1,1);
plot(t, x, 'blue',LineWidth=1.5);
hold on;
plot(t, x_fs1, 'red',LineWidth=1);
title(['Square Wave and its Fourier Series N = ',num2str(N1)]);
legend('Square Wave', 'Fourier Series');
axis([min(t) max(t) -0.5 1.5]);
grid on;

% plot N = 16
subplot
subplot(2,1,2);
plot(t, x, 'blue',LineWidth=1.5);
hold on;
plot(t, x_fs2, 'red',LineWidth=1);
title(['Square Wave and its Fourier Series N = ',num2str(N2)]);
legend('Square Wave', 'Fourier Series');
axis([min(t) max(t) -0.5 1.5]);
grid on;

sgtitle('Part 1 : N = 8 and N = 16');

%% part 2 : fourier series with N = 64

% Parameters
f = 0.5;                % Frequency of the square wave
T = 1 / f;            % Period of the square wave
N = 64;               % Number of terms in the Fourier series
t = -2*T:0.001:2*T;      % Time vector

% Generate a square wave signal
x = (square(2*pi*f*t)./2+0.5);

% Initialize the Fourier series approximation (set to a0)
x_fs = zeros(size(t))+(sum(x)/length(t));

% Calculate the Fourier series
for n = 1:2:N  % Only odd harmonics contribute to a square wave
    x_fs = x_fs + 2/(n*pi) * sin(2 * pi * n * f * t);
end


% Plot the square wave and its Fourier series
figure(2);
plot(t, x, 'blue',LineWidth=1.5);
hold on;
plot(t, x_fs, 'red',LineWidth=1);
yline(max(x),'b--',LineWidth=2);
yline(max(x_fs),'r--',LineWidth=2);
% title(sprintf('Square Wave and its Fourier Series N = {%d}',N));
legend('Square Wave', 'Fourier Series','Square Wave Max', 'Fourier Series Max');
grid on;

sgtitle(sprintf('square wave and its FS with N = %d, with the overshoot comparison\novershoot: %0.2f%%',N,(max(x_fs)-max(x))*100));

