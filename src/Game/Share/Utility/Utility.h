
#pragma once

#include "../../AppEnv.h"

namespace utl
{

    class Colli
    {
    public:
        static bool rect_Point(const Vec2f& pos, const Vec2f& size, const Vec2f& other_Pos);
        static bool rect_Rect(const Vec2f& pos, const Vec2f& size, const Vec2f& other_Pos, const Vec2f& other_Size);
        static bool rect_Circle(const Vec2f& pos, const Vec2f& size, const Vec2f& other_Pos, const float& other_Size);
        static bool circle_Point(const Vec2f& pos, const float& size, const Vec2f& other_Pos);
        static bool circle_Circle(const Vec2f& pos, const float& size, const Vec2f& other_Pos, const float& other_Size);
        static bool ellipse_Point(const Vec2f& pos, const Vec2f& size, const float& angle, const Vec2f& other_Pos);
    private:
        Colli() {}
        ~Colli() {}
    };

    class Coloring
    {
    public:
        Color html(const std::string& str);
    private:
        Coloring() {}
        ~Coloring() {}
    };

    class FileIO
    {
    public:
        template <class _Ty>
        static int load(const std::string& path, _Ty& data)
        {
            std::fstream in_file(path, std::ios::in | std::ios::binary);

            if (!in_file) return 1;

            std::cout << "loading : " << path << " : FileIO" << std::endl;

            while (!in_file.eof()) in_file.read((char*)&data, sizeof(_Ty));

            return 0;
        }
        template <class _Ty>
        static int save(const std::string& path, const _Ty& data)
        {
            std::fstream out_file(path, std::ios::out | std::ios::binary);

            if (!out_file) return 1;

            std::cout << "saveing : " << path << " : FileIO" << std::endl;

            out_file.write((char*)&data, sizeof(_Ty));

            return 0;
        }
        template <class _Ty>
        static int load(const std::string& path, std::vector<_Ty>& array)
        {
            std::fstream in_file(path, std::ios::in | std::ios::binary);

            if (!in_file) return 1;

            std::cout << "loading : " << path << " : FileIO" << std::endl;

            while (!in_file.eof())
            {
                _Ty temp;
                in_file.read((char*)&temp, sizeof(_Ty));
                if (in_file.tellg() % sizeof(_Ty) == 0) array.push_back(temp);
            }

            return 0;
        }
        template <class _Ty>
        static int save(const std::string& path, const std::vector<_Ty>& array)
        {
            std::fstream out_file(path, std::ios::out | std::ios::binary);

            if (!out_file) return 1;

            std::cout << "saveing : " << path << " : FileIO" << std::endl;

            for (auto obj : array) out_file.write((char*)&obj, sizeof(_Ty));

            return 0;
        }
    private:
        FileIO() {}
        ~FileIO() {}
    };

}