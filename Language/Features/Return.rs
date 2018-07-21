protocol Protocol
{
    bloc Bloc()
    {
        recv Recv1
        {
            return;
        }
        or send Send1
        {
        }

        recv Recv2
        {
        }
        or send Send2
        {
        }
    }

    proc Processor()
    {
        recv Recv3
        {
            return;
        }
        or send Send3
        {
        }

        recv Recv4
        {
        }
        or send Send4
        {
        }
    }
}