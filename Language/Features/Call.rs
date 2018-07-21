protocol Protocol
{
    bloc Bloc1()
    {
        recv Recv1;
    }

    bloc Bloc2()
    {
        Bloc1();

        recv Recv2;
    }

    proc Processor()
    {
        Bloc2();

        recv Recv3;
    }
}
