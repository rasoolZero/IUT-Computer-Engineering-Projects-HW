function [y] = x_t_without_heaviside(t)

y = ones(size(t));
y((t<-1) | (t>2 & t<4)) = 0;

end