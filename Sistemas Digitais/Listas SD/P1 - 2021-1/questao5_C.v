module comp4bit(A, B, V2in, V1in, V3in, V2out, V1out, V3out);
    input[3:0] A, B;
    input V2in, V1in, V3in;
    output reg V1out, V2out, V3out;

    initial begin
        V2out = 0;
        V1out = 0;
        V3out = 0;
    end

    always @(A, B, V2in, V1in, V3in)
    begin
        if (A > B)
        begin
            V2out <= 0;
            V1out <= 0;
            V3out <= 0;
        end
        else if(A < B)
        begin
            V2out <= 0;
            V1out <= 0;
            V3out <= 1;
        end
        else if(V1in == 1)
        begin
            V2out <= 0;
            V1out <= 1;
            V3out <= 0;
        end
        else if(V3in == 1)
        begin
            V2out <= 0;
            V1out <= 0;
            V3out <= 1;
        end
        else 
        begin
            V2out <= 1;
            V1out <= 0;
            V3out <= 0;
        end
    end
endmodule

/*Nesse código, eu crio o primeiro comparador, e após vou fazendo as comparações e 
mudando as saídas de acordo com os valores de entradas ou comparações entre A e B. Por exemplo, 
caso a entrada "V1in" seja 1, sua saída também será 1, enquanto as outras serão 0, assim como 
nas outras comparações. Após isso eu encerro o módulo.*\


