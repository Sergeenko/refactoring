class IPlayer
{
public:
    virtual void fine(size_t) = 0;
    virtual void reward(size_t) = 0;
    virtual uint8_t rollDice() = 0;

private:
    int m_money{0};
    size_t m_currentPosition{0};
};