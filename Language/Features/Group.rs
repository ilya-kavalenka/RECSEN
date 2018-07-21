protocol Protocol
{
    group Group1;

    group Group2
    {
    }

    group Group3
    {
        int32 Field1;
        int32 Field2;
        int32 Field3(6);
        int32 Field4;
    }
}