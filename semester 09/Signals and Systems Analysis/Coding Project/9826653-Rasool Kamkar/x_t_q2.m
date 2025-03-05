function y = x_t_q2(t)

y = zeros(size(t));
y_exp = (exp(-t));
y((t>=1 & t<=3)) = y_exp(t>=1 & t<=3);

end

