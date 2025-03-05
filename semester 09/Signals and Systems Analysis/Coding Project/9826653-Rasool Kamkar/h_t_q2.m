function y = h_t_q2(t)

y = zeros(size(t));
y((1<=t & t<=3)) = t((1<=t & t<=3));
y((3<t & t<=5)) = ones(size(t(3<t & t<=5)));

end

