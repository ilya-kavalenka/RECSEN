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

    processor Processor()
    {
        Bloc();

        recv Recv2
        {
            disconnect "text";
        }
        or send Send2
        {
        }
    }
}