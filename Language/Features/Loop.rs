protocol Protocol
{
    processor Processor1()
    {
        loop recv Recv;
    }

    processor Processor2()
    {
        loop 
        {
            recv Recv1;
            recv Recv2;
        }
    }

    processor Processor3()
    {
        loop 
        {
            recv Recv1
            {
            }
            or send Send1
            {
                break;
            }

            recv Recv2
            {
            }
            or send Send2
            {
            }
        }
    }

    processor Processor4()
    {
        @L loop 
        {
            recv Recv1
            {
                loop
                {
                    recv Recv3
                    {
                    }
                    or send Send3
                    {
                        break;
                    }

                    recv Recv4
                    {
                    }
                    or send Send4
                    {
                        continue L;
                    }
                }
            }
            or send Send1
            {
                break;
            }

            recv Recv2
            {
            }
            or send Send2
            {
            }
        }
    }
}