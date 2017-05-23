protocol Protocol
{
    processor Processor1()
    {
        recv Recv or send Send;
    }

    processor Processor2()
    {
        recv Recv
        {
        }
        or send Send
        {
        }
    }
}