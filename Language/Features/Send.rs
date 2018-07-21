protocol Protocol
{
    message Message1;

    message Message2;

    proc Processor1()
    {
        send;            
        send (Message1);
        send (Message1, Message2);
        send ();
    }

    proc Processor2()
    {
        send Send1;
        send Send2(Message2);
        send Send3(Message1, Message2);
        send Send4();
    }

    proc Processor3()
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

    proc Processor4()
    {
        send Send1 send Send2(Message2) send Send3(Message1, Message2) send Send4();
    }

    proc Processor5()
    {
        send Send1 send Send2(Message2) send Send3(Message1, Message2) send Send4() {}
    }

    proc Processor6()
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

    proc Processor7()
    {
        send Send1 send Send2(Message2); 
        send Send3(Message1, Message2) send Send4();
    }

    proc Processor8()
    {
        send Send1 send Send2(Message2) {}
        send Send3(Message1, Message2) send Send4() {}
    }

    proc Processor9()
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

    proc Processor10()
    {
        send Send1 { send Send2(Message2); send Send3(Message1, Message2) send Send4(); }
    }

    proc Processor11()
    {
        send Send1 { send Send2(Message2) {} send Send3(Message1, Message2) send Send4() {} }
    }

    proc Processor12()
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