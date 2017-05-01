protocol Protocol
{
    message Message1;

    message Message2;

    processor Processor1()
    {
        send;            
        send (Message1);
        send (Message1, Message2);
        send ();
    }

    processor Processor2()
    {
        send Send1;
        send Send2(Message2);
        send Send3(Message1, Message2);
        send Send4();
    }

    processor Processor3()
    {
        send Send1
        {
        }

        send Send2(Message2)
        {
        }

        send Send3(Message1, Message2)
        {
        }

        send Send4()
        {
        }
    }

    processor Processor4()
    {
        send Send1 send Send2(Message2) send Send3(Message1, Message2) send Send4();
    }

    processor Processor5()
    {
        send Send1 send Send2(Message2) send Send3(Message1, Message2) send Send4() {}
    }

    processor Processor6()
    {
        send Send1
        {
            send Send2(Message2)
            {
                send Send3(Message1, Message2)
                {
                    send Send4()
                    {
                    }
                }
            }
        }
    }

    processor Processor7()
    {
        send Send1 send Send2(Message2); 
        send Send3(Message1, Message2) send Send4();
    }

    processor Processor8()
    {
        send Send1 send Send2(Message2) {}
        send Send3(Message1, Message2) send Send4() {}
    }

    processor Processor9()
    {
        send Send1 
        {
            send Send2(Message2) 
            {
            }
        }

        send Send3(Message1, Message2) 
        {
            send Send4()
            {
            }
        }
    }

    processor Processor10()
    {
        send Send1 { send Send2(Message2); send Send3(Message1, Message2) send Send4(); }
    }

    processor Processor11()
    {
        send Send1 { send Send2(Message2) {} send Send3(Message1, Message2) send Send4() {} }
    }

    processor Processor12()
    {
        send Send1 
        {
            send Send2(Message2) 
            {
            }
            
            send Send3(Message1, Message2) 
            {
                send Send4()
                {
                }
            }
        }
    }
}