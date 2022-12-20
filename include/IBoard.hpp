class IBoard
{
    class Iiterator
    {
        virtual Iiterator& next() = 0;
        virtual ISquare& currentSquare() const = 0;
    };
}