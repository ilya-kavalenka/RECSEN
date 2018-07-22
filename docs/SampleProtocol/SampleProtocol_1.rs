/*
    The basic protocol
*/

protocol SampleProtocol(1,0)
{
    enum Side
    {
        Bid,
        Ask
    }

    group SnapshotRefreshEntry
    {
        Side Side;
        int32 Qty;
        double Price;
        int32? Orders;
    }

    message SnapshotRefresh
    {
        string Symbol;
        SnapshotRefreshEntry[] Entries;
    }

    proc Client()
    {
        recv Snapshot(SnapshotRefresh)
            repeat;
    }

    proc Server()
    {
        send (SnapshotRefresh)
            repeat;
    }
}