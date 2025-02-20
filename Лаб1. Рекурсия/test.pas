{$mode objfpc}

var
    a: integer = 1;
    b: integer = 1;
    s: integer = 0;
    i: real = 1;
    k: integer = 0;


BEGIN
    while ((1/i) < 0.1) do
    begin
        s := s + (1/i);
        i := i + 1;
    end;


    writeln(s);



END.
