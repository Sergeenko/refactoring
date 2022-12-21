class IBoard
{
public:
    virtual ~IBoard() = default;
    class Iiterator
    {
    public:
        virtual ~Iiterator() = default;
        virtual Iiterator& next() = 0;
        virtual ISquare& currentSquare() const = 0;
    };
    virtual Iiterator& begin() = 0;
};