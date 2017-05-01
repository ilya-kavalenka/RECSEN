protocol Protocol
{
    processor Processor1()
    {
        recv Recv1 or send Send1;
    }

    processor Processor2()
    {
        recv Recv1
        {
        }
        or send Send1
        {
        }
        or recv Recv2
        {
        }
        or send Send2
        {
        }
    }
}