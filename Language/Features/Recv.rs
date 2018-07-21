protocol Protocol
{
    message Message1;

    message Message2;

    proc Processor1()
    {
        recv;            
        recv (Message1);
        recv (Message1, Message2);
        recv ();
    }

    proc Processor2()
    {
        recv Recv1;
        recv Recv2(Message2);
        recv Recv3(Message1, Message2);
        recv Recv4();
    }

    proc Processor3()
    {
        recv Recv1
        {
        }

        recv Recv2(Message2)
        {
        }

        recv Recv3(Message1, Message2)
        {
        }

        recv Recv4()
        {
        }
    }

    proc Processor4()
    {
        recv Recv1 recv Recv2(Message2) recv Recv3(Message1, Message2) recv Recv4();
    }

    proc Processor5()
    {
        recv Recv1 recv Recv2(Message2) recv Recv3(Message1, Message2) recv Recv4() {}
    }

    proc Processor6()
    {
        recv Recv1
        {
            recv Recv2(Message2)
            {
                recv Recv3(Message1, Message2)
                {
                    recv Recv4()
                    {
                    }
                }
            }
        }
    }

    proc Processor7()
    {
        recv Recv1 recv Recv2(Message2); 
        recv Recv3(Message1, Message2) recv Recv4();
    }

    proc Processor8()
    {
        recv Recv1 recv Recv2(Message2) {}
        recv Recv3(Message1, Message2) recv Recv4() {}
    }

    proc Processor9()
    {
        recv Recv1 
        {
            recv Recv2(Message2) 
            {
            }
        }

        recv Recv3(Message1, Message2) 
        {
            recv Recv4()
            {
            }
        }
    }

    proc Processor10()
    {
        recv Recv1 { recv Recv2(Message2); recv Recv3(Message1, Message2) recv Recv4(); }
    }

    proc Processor11()
    {
        recv Recv1 { recv Recv2(Message2) {} recv Recv3(Message1, Message2) recv Recv4() {} }
    }

    proc Processor12()
    {
        recv Recv1 
        {
            recv Recv2(Message2) 
            {
            }
            
            recv Recv3(Message1, Message2) 
            {
                recv Recv4()
                {
                }
            }
        }
    }
}