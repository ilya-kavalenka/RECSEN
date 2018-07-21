protocol Protocol
{
    message Message1;

    message Message2
    {
    }

    message Message3(10)
    {
        int32 Field1;
        int32 Field2;
        int32 Field3(32);
        int32 Field4;
    }

    message Message4 : Message3
    {
        int32 Field5;
        int32 Field6;
        int32 Field7(64);
        int32 Field8;
    }
}