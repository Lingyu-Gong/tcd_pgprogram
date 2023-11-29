% % input matrix as 3 * 3
% % Calculate the diagonal sum value

diag_sum = diagonalSum() ;

function diag_sum = diagonalSum()
    % Ask for the number of rows and columns from the user
    row = input("Your number of Matrix Rows is: ");
    col = input("Your number of Matrix Cols is: ");

    % Make judgement
    if(row ~= col)
        disp("Please input a matrix with the same number of rows and columns");
        diag_sum = NaN; 
        return;
    end

    % Initialization
    X = zeros(row, col);
    diag_sum = 0;
    flag = 1;

    % Fill the matrix with user input
    for i = 1: row
        for j = 1: col
            X(i, j) = input(sprintf("Enter your matric element one by one (%d, %d): ", i, j));
        end
    end
    disp("Your Matrix is:");
    disp(X);
    
    % Calculate the sum of the diagonal
    for i = 1: row
        diag_sum = diag_sum + X(i, i);
    end
    disp("The sum of diagonal value") ;
    disp(diag_sum) ;
   
    % make jugement Identity Matrix or not
    for i = 1: row
        for j = 1: col
            % check it is 
            if(i == j && X(i, j) == 1) && (i ~= j && X(i, j) == 0)
                flag = 1 ;
            % check not 
            elseif(i == j && X(i, j) ~= 1) || (i ~= j && X(i, j) ~= 0)
                flag = 0 ;
            end
        end
    end
    if (flag == 1)
            disp("The input matrix is an identity matrix.");
        else
            disp("The input matrix is not an identity matrix.");
    end
end
  
    