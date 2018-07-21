protocol Protocol
{
    bloc Bloc()
    {
        recv Recv1
        {
            disconnect;
        }
        or send Send1
        {
        }
    }

    proc Processor()
    {
        Bloc();

        recv Recv2
        {
            disconnect;
        }
        or send Send2
        {
        }
    }
}