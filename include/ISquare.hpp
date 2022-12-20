class IPlayer;

class ISquare
{
    virtual void onEntry(IPlayer&) = 0;

    virtual ~ISquare() = 0;
};