protocol Protocol
{
    message Message1;

    message Message2;

    processor Processor1()
    {
        recv;            
        recv (Message1);
        recv (Message1, Message2);
        recv ();
    }

    processor Processor2()
    {
        recv Recv1;
        recv Recv2(Message2);
        recv Recv3(Message1, Message2);
        recv Recv4();
    }

    processor Processor3()
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

    processor Processor4()
    {
        recv Recv1 recv Recv2(Message2) recv Recv3(Message1, Message2) recv Recv4();
    }

    processor Processor5()
    {
        recv Recv1 recv Recv2(Message2) recv Recv3(Message1, Message2) recv Recv4() {}
    }

    processor Processor6()
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

    processor Processor7()
    {
        recv Recv1 recv Recv2(Message2); 
        recv Recv3(Message1, Message2) recv Recv4();
    }

    processor Processor8()
    {
        recv Recv1 recv Recv2(Message2) {}
        recv Recv3(Message1, Message2) recv Recv4() {}
    }

    processor Processor9()
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

    processor Processor10()
    {
        recv Recv1 { recv Recv2(Message2); recv Recv3(Message1, Message2) recv Recv4(); }
    }

    processor Processor11()
    {
        recv Recv1 { recv Recv2(Message2) {} recv Recv3(Message1, Message2) recv Recv4() {} }
    }

    processor Processor12()
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