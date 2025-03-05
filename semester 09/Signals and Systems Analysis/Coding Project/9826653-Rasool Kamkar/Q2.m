%% Part 1: same size square pulse convolution

n = -50:50;
% pulse with length of 21
x = cat(2,repelem(0,40),repelem(1,21),repelem(0,40));
% calculate same size convolution
y = conv(x,x,'same');

% new figure
figure(1);

% plotting x (pulse)
subplot(1,2,1);
stem(n,x,MarkerSize=3);
title('x[n]');
xlabel('n');
ylabel('x[n]');
axis([-50 50 -0.5 1.5]);
grid on;

% plotting y (convolution)
subplot(1,2,2);
stem(n,y,MarkerSize=3,color='red');
title('y[n] = x[n] * x[n]');
xlabel('n');
ylabel('y[n]');
height = max(y);
axis([-50 50 -height/2 height*1.5]);
grid on;

% title
sgtitle('Same Size Square Pulse Convolution');


%% Part 2: square pulse convolution
n = -50:50;

% pulse with length of 21
x1 = cat(2,repelem(0,40),repelem(1,21),repelem(0,40));

% pulse with length of 41
x2 = cat(2,repelem(0,30),repelem(1,41),repelem(0,30));

% calculate convolution
y = conv(x1,x2,'same');

% new figure
figure(2);

% plotting x1
subplot(1,3,1);
stem(n,x1,MarkerSize=3);
title('x1[n]');
xlabel('n');
ylabel('x1[n]');
axis([-50 50 -0.5 1.5]);
grid on;

% plotting x2
subplot(1,3,2);
stem(n,x2,MarkerSize=3);
title('x2[n]');
xlabel('n');
ylabel('x2[n]');
axis([-50 50 -0.5 1.5]);
grid on;

% plotting y
subplot(1,3,3);
stem(n,y,MarkerSize=3,color='red');
title('y[n] = x1[n] * x2[n]');
xlabel('n');
ylabel('y[n]');
height = max(y);
axis([-50 50 -height/2 height*1.5]);
grid on;


%% part 3: system response
% Define the time vector for signals
t = -4:0.005:12;  % Adjust the time range and step size accordingly

% Define the signals x(t) and h(t)
x_t = x_t_q2(t);
h_t = h_t_q2(t);

% Calculate the convolution using the conv function
y_t_q2 = conv(x_t, h_t, 'same');

% new figure
figure(3);

% plot x(t)
subplot(3, 1, 1);
plot(t, x_t,'blue','LineWidth',2);
title('Signal x(t)');

% plot h(t)
subplot(3, 1, 2);
plot(t, h_t,'green','LineWidth',2);
title('Signal h(t)');

% plot convolution result y(t) 
subplot(3, 1, 3);
plot(t, y_t_q2,'red','LineWidth',2);
title('Convolution: y(t) = x(t) * h(t)');

% change title of figure
sgtitle('Convolution of x(t) and h(t)');
