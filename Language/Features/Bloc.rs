protocol Protocol
{
    bloc Bloc1();

    bloc Bloc2()
    {
    }

    bloc Bloc3()
    {
        recv Recv1;
        recv Recv2;
        @L recv Recv3;
        recv Recv4;
    }
}
