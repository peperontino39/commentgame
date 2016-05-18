
#include "Utility.h"

namespace utl 
{

    bool Colli::rect_Point(const Vec2f& pos, const Vec2f& size, const Vec2f& other_Pos)
    {
        if (pos.x() < other_Pos.x() && other_Pos.x() < pos.x() + size.x() &&
            pos.y() < other_Pos.y() && other_Pos.y() < pos.y() + size.y())
            return true;
        else return false;
    }
    bool Colli::rect_Rect(const Vec2f& pos, const Vec2f& size, const Vec2f& other_Pos, const Vec2f& other_Size)
    {
        if (pos.x() < other_Pos.x() + other_Size.x() && other_Pos.x() < pos.x() + size.x() &&
            pos.y() < other_Pos.y() + other_Size.y() && other_Pos.y() < pos.y() + size.y())
            return true;
        else return false;
    }
    bool Colli::rect_Circle(const Vec2f& pos, const Vec2f& size, const Vec2f& other_Pos, const float& other_Size)
    {
        bool A, B, C, D, E, F;

        const Vec2f r1 = pos;
        const Vec2f r2 = pos + size;
        const Vec2f c = other_Pos;
        const float r = other_Size;

        A = (r1.x() < c.x()) & (c.x() < r2.x()) & (r1.y() - r < c.y()) & (c.y() < r2.y() + r);
        B = (r1.x() - r < c.x()) & (c.x() < r2.x() + r) & (r1.y() < c.y()) & (c.y() < r2.y());
        C = (r1.x() - c.x()) * (r1.x() - c.x()) + (r1.y() - c.y()) * (r1.y() - c.y()) < r * r;
        D = (r2.x() - c.x()) * (r2.x() - c.x()) + (r1.y() - c.y()) * (r1.y() - c.y()) < r * r;
        E = (r2.x() - c.x()) * (r2.x() - c.x()) + (r2.y() - c.y()) * (r2.y() - c.y()) < r * r;
        F = (r1.x() - c.x()) * (r1.x() - c.x()) + (r2.y() - c.y()) * (r2.y() - c.y()) < r * r;

        return A | B | C | D | E | F;
    }
    bool Colli::circle_Point(const Vec2f& pos, const float& size, const Vec2f& other_Pos)
    {
        const Vec2f radius_Pos = other_Pos - pos;
        const float radius = size;
        if (radius_Pos.x() * radius_Pos.x() + radius_Pos.y() * radius_Pos.y()
            < radius * radius)
            return true;
        else return false;
    }
    bool Colli::circle_Circle(const Vec2f& pos, const float& size, const Vec2f& other_Pos, const float& other_Size)
    {
        const Vec2f radius_Pos = other_Pos - pos;
        const float radius = size + other_Size;
        if (radius_Pos.x() * radius_Pos.x() + radius_Pos.y() * radius_Pos.y()
            < radius * radius)
            return true;
        else return false;
    }
    bool Colli::ellipse_Point(const Vec2f& pos, const Vec2f& size, const float& angle, const Vec2f& other_Pos)
    {
        float Ofs_x = other_Pos.x() - pos.x();
        float Ofs_y = other_Pos.y() - pos.y();
        float After_x = Ofs_x * cos(angle) + Ofs_y * sin(angle);
        float After_y = size.x() / size.y() * (-Ofs_x * sin(angle) + Ofs_y * cos(angle));

        if (After_x * After_x + After_y * After_y <= size.x() * size.x())
            return true;
        return false;

    }

    Color Coloring::html(const std::string& str)
    {
        if (str[0] != '#') return Color::white;
        if (str.size() != 7) return Color::white;

        Color col = Color::white;
        col.r() = std::stof("0X" + str.substr(1, 2)) / 256.0f;
        col.g() = std::stof("0X" + str.substr(3, 2)) / 256.0f;
        col.b() = std::stof("0X" + str.substr(5, 2)) / 256.0f;

        return col;
    }

}