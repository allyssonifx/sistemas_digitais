module comp8bit(A, B, V2i, V1i, V3i, V2, V1, V3);
    input[7:0]A, B;
    input V2i, V1i, V3i;
    output V2, V1, V3;

    wire LowV2, LowV1, LowV3;

    comp4bit C1(A[3:0], B[3:0], V2i, V1i, V3i, LowV2, LowV1, LowV3);

    comp4bit C2(A[7:4], B[7:4], LowV2, LowV1, LowV3, V2, V1, V3);


/* Nesse código, eu crio o segundo módulo e inicio as entradas dele como 7:0. Correlaciono os dois 
com as entradas, primeiro as  de 3:0 bits e depois as de 7:4 como está na letra B da questão. C1 e
C2 correspondem aos comparadores 1 e 2, ambos de 4 bits cada*\