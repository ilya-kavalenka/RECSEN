protocol Protocol
{
    processor Processor1()
    {
        loop recv Recv1;     
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
            or recv Recv2
            {
                break;
            }

            recv Recv3
            {
            }
            or recv Recv4
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
                    recv Recv5
                    {
                    }
                    or recv Recv6
                    {
                        break;
                    }

                    recv Recv7
                    {
                    }
                    or recv Recv8
                    {
                        continue L;
                    }
                }
            }
            or recv Recv2
            {
                break;
            }

            recv Recv3
            {
            }
            or recv Recv4
            {
            }
        }
    }
}