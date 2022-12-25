#pragma once

class IBoard
{
public:
    virtual ~IBoard() = default;
    class Iiterator
    {
    public:
        virtual ~Iiterator() = default;
        virtual Iiterator& next() = 0;
        [[nodiscard]] virtual ISquare& currentSquare() const = 0;
    };
    virtual Iiterator& begin() = 0;
    virtual size_t getSize() const = 0;
};
