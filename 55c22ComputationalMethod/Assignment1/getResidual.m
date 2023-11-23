function [res] = getResidual(data, coeffs)
    coeffs = [1, coeffs] ;
    res = conv(coeffs, data);
end