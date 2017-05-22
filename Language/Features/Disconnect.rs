protocol Protocol
{
    bloc Bloc()
    {
        recv Recv1
        {
            disconnect;
        }
        or recv Recv2
        {
        }
    }

    processor Client()
    {
        Bloc();

        recv Recv1
        {
            disconnect "text";
        }
        or recv Recv2
        {
        }
    }
}