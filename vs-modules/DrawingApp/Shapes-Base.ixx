export module Shapes:Base;

import :Point;

import std;

export 
namespace Shapes
{
    class Shape
    {
    public:
        virtual ~Shape() = default;
        virtual void move(int dx, int dy) = 0;
        virtual void draw() const = 0;
    };

    class ShapeBase : public Shape
    {
        Point coord_; // composition
    public:
        Point coord() const
        {
            return coord_;
        }

        void set_coord(const Point& pt)
        {
            coord_ = pt;
        }

        ShapeBase(int x = 0, int y = 0)
            : coord_{x, y}
        {}

        void move(int dx, int dy) override
        {
            coord_.translate(dx, dy);
        }
    };
}