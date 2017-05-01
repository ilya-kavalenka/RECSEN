protocol Protocol
{
    processor Processor1()
    {
        recv Recv1 repeat;
    }

    processor Processor2()
    {
        recv Recv1
        {
            repeat;
        }
        or recv Recv2
        {
        }
    }

    processor Processor3()
    {
        @L recv Recv3
        {
            recv Recv5
            {
                repeat;
            }
            or recv Recv6
            {
                repeat L;
            }
        }
        or recv Recv4
        {
        }
    }
}