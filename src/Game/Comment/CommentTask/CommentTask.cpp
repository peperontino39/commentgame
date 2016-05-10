#include "CommentTask.h"
#include "../FlowString/FlowString.h"
#include "../CommentOption/CommentOption.h"
#include "../CommentWindow/CommentWindow.h"
#include "../CommentStack/CommentStack.h"

#include "../../AppEnv.h"

#include <vector>
#include <set>

using Comments = std::vector<FlowString>;
using Fonts = std::vector<Font>;

struct CommentTask::_m_CommentTask
{
    Comments comments;
private:
    Font temp = Font("res/Font/meiryo.ttc");    // ���Font�̃R���X�g���N�^���Ă�ł����Ȃ��ƃ������[�A�N�Z�X�ᔽ�ɂȂ�܂��B���R�͒m��܂���B
public:
    Fonts fonts;
};

std::shared_ptr<CommentTask::_m_CommentTask> CommentTask::member = std::make_shared<CommentTask::_m_CommentTask>();

void CommentTask::fontSizeUpdate()
{
    member->fonts.at(0).size((CommentWindow::size.y() / CommentOption::lines) * 0.5f);
    member->fonts.at(1).size((CommentWindow::size.y() / CommentOption::lines) * 0.8f);
    member->fonts.at(2).size((CommentWindow::size.y() / CommentOption::lines) * 1.0f);
}

void CommentTask::setup()
{
    member->fonts = { Font("res/Font/meiryo.ttc"), Font("res/Font/meiryo.ttc"), Font("res/Font/meiryo.ttc") };
    fontSizeUpdate();

    member->comments.push_back(FlowString("wwwwwwwwwwwwwwwwww", FlowString::Size::SMALL));
    member->comments.push_back(FlowString("����", FlowString::Size::BIG));
    member->comments.push_back(FlowString("�K���ȃR�����g�ł�"));
    member->comments.push_back(FlowString("�g�L���L���{�����b�V��"));
    member->comments.push_back(FlowString("���@�@���@��"));
    member->comments.push_back(FlowString("�ǂ����Ă����Ȃ���"));
    member->comments.push_back(FlowString("�e�X�g"));
    member->comments.push_back(FlowString("�悭�킩���"));
    member->comments.push_back(FlowString("����������"));
    member->comments.push_back(FlowString("(�L�E�ցE�M)"));
    member->comments.push_back(FlowString("�X�v���g�D�[��"));
    member->comments.push_back(FlowString("����"));
    member->comments.push_back(FlowString("�����ɃR�����g��łƏd�Ȃ��Ă��܂��̂�"));
    member->comments.push_back(FlowString("�ǂ������炢�����̂��ˁ["));
    member->comments.push_back(FlowString("�ł��܂��Ȃ�Ƃ��Ȃ������"));

    member->comments.push_back(FlowString("wwwwwwwwwww", FlowString::Type::BOTTOM));
    member->comments.push_back(FlowString("�R�����g", FlowString::Type::BOTTOM));
}

void CommentTask::clear()
{
    member->comments.clear();
    member->fonts.clear();

    CommentOption::clear();
    CommentStack::clear();
}

void CommentTask::draw()    //�@�R�����g�̕`��͏�R�������R���������R���̏��ł��܂��B
{
    glPushMatrix();

    glTranslatef(CommentWindow::pos.x(), CommentWindow::pos.y(), 0);

    for (auto& obj : member->comments)
    {
        switch (obj.Get_Type())
        {
        case FlowString::Type::TOP:
            obj.drawStop(member->fonts);
            break;
        case FlowString::Type::MIDDLE:
            obj.drawFlow(member->fonts);
            break;
        case FlowString::Type::BOTTOM:
            obj.drawStop(member->fonts);
            break;
        default:
            break;
        }
    }

    drawBox(0, 0, CommentWindow::size.x(), CommentWindow::size.y(), 1, Color::red);
    drawLine(CommentWindow::size.x() - CommentWindow::size.x() * 1.1f, CommentWindow::size.y() / 2.0f,
             CommentWindow::size.x() * 1.1f, CommentWindow::size.y() / 2.0f,
             1, Color::red);
    drawLine(CommentWindow::size.x() / 2.0f, CommentWindow::size.y() - CommentWindow::size.y() * 1.1f,
             CommentWindow::size.x() / 2.0f, CommentWindow::size.y() * 1.1f,
             1, Color::red);

    glPopMatrix();
}

void CommentTask::update()
{
    //  �R�����g�E�B���h�E�̌��_��T�C�Y���ύX���ꂽ��Ă΂��B
    if (CommentWindow::isChange())
    {
        //  �����̃N���X��font���T�C�Y�ύX
        fontSizeUpdate();
        //  �R�����g�o�^�p�̃X�^�b�N���폜
        CommentStack::clear();
        //  �R�����g��o�^����Ƃ��ɁAy���̍��������肵�Ă��邽�߁A�R�����g���ēo�^���Ċ���
        for (auto& obj : member->comments) obj.regist();
        //  ������x�R�����g�o�^�p�̃X�^�b�N���폜
        CommentStack::clear();
    }

    CommentWindow::update();
    CommentOption::update();

    CommentStack::Access(FlowString::Type::TOP).update();
    CommentStack::Access(FlowString::Type::MIDDLE).update();
    CommentStack::Access(FlowString::Type::BOTTOM).update();

    for (auto itr = member->comments.begin(); itr != member->comments.end();)
    {
        itr->update();
        if (!itr->isActive())
        {
            member->comments.erase(itr);
        }
        else
        {
            ++itr;
            continue;
        }
    }

    if (env.isPressKey(GLFW_KEY_LEFT_CONTROL) && env.isPushKey(GLFW_KEY_C))
    {
        member->comments.push_back(FlowString("wwwwwwwwwww"));
    }
}
