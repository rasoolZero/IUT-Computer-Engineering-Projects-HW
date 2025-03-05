%% Part 1: x(t) using Heaviside
figure(1);
fplot(@(x) x_t_with_heaviside(x),color='red',linewidth=1.5);
axis([-4 6 -0.5 1.5]);
title('x(t) using heaviside');
grid on;

%% Part 2: x(t) without heaviside
figure(2);
fplot(@(x) x_t_without_heaviside(x),linewidth=1.5);
axis([-4 6 -0.5 1.5]);
title('x(t) without using heaviside');
grid on;

%% Part 3: ramp
figure(3);
x = -3:1:6;
y = x;
stem(x,y,"filled",linewidth = 1);
title('ramp from -3 to 6');
grid on;

%% Part 4: 
% inputs
r = input('Enter the radius (r): ');
w = input('Enter the angular frequency (omega): ');

n = -100:100; 
x_n = (r.^n) .* exp(1j .* w .* n);

% plotting real part
figure(4);
subplot(2, 2, 1);
stem(n, real(x_n),'blue',MarkerSize=3);
title('Real Part');
xlabel('n');
ylabel('Re{x[n]}');

% plotting imaginary part
subplot(2, 2, 2);
stem(n, imag(x_n),'red',MarkerSize=3);
title('Imaginary Part');
xlabel('n');
ylabel('Im{x[n]}');

% Plotting phase
subplot(2, 2, 3);
stem(n, angle(x_n),'green',MarkerSize=3);
title('Phase');
xlabel('n');
ylabel('Phase of x[n]');

% plotting magnitude
subplot(2, 2, 4);
abs_st = stem(n, abs(x_n),MarkerSize=3,color=[0.4940 0.1840 0.5560]);
title('Magnitude');
xlabel('n');
ylabel('|x[n]|');

% title
sgtitle(['Discrete Function x[n] = (r^n)e^{jwn} with r = ', num2str(r), ', omega = ', num2str(w)]);