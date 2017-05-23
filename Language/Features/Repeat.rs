protocol Protocol
{
    processor Processor1()
    {
        recv Recv repeat;
    }

    processor Processor2()
    {
        recv Recv1
        {
            repeat;
        }
        or send Send1
        {
        }
    }

    processor Processor3()
    {
        @L recv Recv1
        {
            recv Recv2
            {
                repeat;
            }
            or send Send2
            {
                repeat L;
            }
        }
        or send Send1
        {
        }
    }
}