function [coeffs, avg1] = estimateARcoeffs(data, model_order)
    % data is the input sample
    % model order is the predict sample ---> P

    % initialize the sample of P
    initial_sample = data(1: model_order);

    % inner_data_block
    inner_data_block = data(model_order + 1: end);

    % normalize
    avg1 = mean(inner_data_block);
    normalize_data = inner_data_block - avg1;

    % implement AR model
    % express matrix R
    % initialize R
    R = zeros(model_order, model_order);

    for i = 1: model_order
        for j = 1: model_order
            for k = model_order + 1: length(inner_data_block)
                R(i, j) = R(i, j) + (inner_data_block(k - i) * inner_data_block(k - j));
            end
        end
    end
    
    % initialize r
    r = zeros(model_order, 1);
    for i = 1: model_order
        for k = model_order + 1: length(inner_data_block)
            r(i) = r(i) + (inner_data_block(k - i) * inner_data_block(k));
        end
    end

    % AR coefficients using matrix inversion
    coeffs = -R \ r;
    coeffs = coeffs' ;
end