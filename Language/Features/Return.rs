protocol Protocol
{
    bloc Bloc()
    {
        recv Recv1
        {
            return;
        }
        or recv Recv2
        {
        }

        recv Recv3
        {
        }
        or recv Recv4
        {
        }
    }

    processor Processor()
    {
        recv Recv1
        {
            return;
        }
        or recv Recv2
        {
        }

        recv Recv3
        {
        }
        or recv Recv4
        {
        }
    }
}