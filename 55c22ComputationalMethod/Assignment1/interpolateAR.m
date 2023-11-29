function [restored, Ak, Au, yk, miss_data2] = interpolateAR(block, detected_missing, coeffs, miss_data)
    % initialize
    % find and store missing point
    % miss_data = zeros(length(detected_missing), 1) ;
    missing_point = find(detected_missing == 1) ;
    % miss_data(missing_point) = 1 ;
    % define all the values
    coeffs_size = length(coeffs) ;
    block_size = length(block) ;
    missing_size = length(missing_point) ;
    hight = (block_size - coeffs_size) - 1 ;
    % iniltial Ak, Au, yk, and yk=[yk1;yk2]
    Ak = zeros(hight, block_size) ;
    restored = zeros(block_size, 1) ;
    Au = zeros(hight, missing_size) ;
    yk = block ;
    mp = isempty(missing_point) ;
    if(mp ~= 1)
        % store the length of missing_point
        yk1 = yk(1: (missing_point(1)- 1), :) ;
        yk2 = yk((missing_point(end) + 1): block_size, :) ;
        yk = [yk1; yk2] ;
        % express the A metrix
        A = toeplitz([coeffs(3), coeffs(2), coeffs(1), 1, ...
        zeros(1, hight)], [coeffs(3), zeros(1, hight)])'; 
        % divided the metrix to express Ak, Au
        Ak = A(:, [1: missing_point(1) - 1, missing_point(end) + 1:end]) ;
        Au = A(:, missing_point: missing_point + 2) ;
        yu = - inv(Au' *Au) * Au' * Ak * yk ;
        restored = [yk1;yu;yk2] ;
    else restored = block ;
    end
    % figure(2) ;
    % plot(missing_point) ;
end