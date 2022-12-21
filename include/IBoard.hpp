class IBoard
{
    class Iiterator
    {
        virtual Iiterator& next() = 0;
        virtual ISquare& currentSquare() const = 0;
    };
    virtual Iiterator& begin() = 0;
};