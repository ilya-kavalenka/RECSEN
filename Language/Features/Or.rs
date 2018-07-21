protocol Protocol
{
    bloc Bloc()
    {
        recv Recv
        {
        }
        or send Send
        {
        }        
    }

    proc Processor1()
    {
        recv Recv1 or send Send1 or Bloc() or Bloc();
    }

    proc Processor2()
    {
        recv Recv
        {
        }
        or send Send
        {
        }
        or Bloc
        (
        )
        or Bloc
        (
        );    
    }
}