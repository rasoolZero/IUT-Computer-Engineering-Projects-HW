function [y] = x_t_with_heaviside(t)
y = heaviside(t+1)-heaviside(t-2)+heaviside(t-4);
end