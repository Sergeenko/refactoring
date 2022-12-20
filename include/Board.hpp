#pragma once

#include <vector>
#include "Squares.hpp"
#include <memory>

struct Board
{
    std::vector<std::shared_ptr<ISquare>> m_squares{
        std::make_shared<StartSquare>(),
        std::make_shared<PenaltySquare>(),
        std::make_shared<PenaltySquare>(),
        std::make_shared<PenaltySquare>(),
        std::make_shared<PenaltySquare>(),
        std::make_shared<PenaltySquare>(),
        std::make_shared<PenaltySquare>(),
        std::make_shared<PenaltySquare>(),
        std::make_shared<PenaltySquare>(),
        std::make_shared<PenaltySquare>(),
        std::make_shared<PenaltySquare>(),
        std::make_shared<PenaltySquare>(),
        std::make_shared<PenaltySquare>(),
        std::make_shared<PenaltySquare>(),
        std::make_shared<PenaltySquare>(),
        std::make_shared<PenaltySquare>(),
        std::make_shared<PenaltySquare>(),
        std::make_shared<PenaltySquare>(),
        std::make_shared<PenaltySquare>(),
        std::make_shared<PenaltySquare>(),
        std::make_shared<PenaltySquare>(),
        std::make_shared<RewardSquare>(),
        std::make_shared<RewardSquare>(),
        std::make_shared<RewardSquare>(),
        std::make_shared<RewardSquare>(),
        std::make_shared<RewardSquare>(),
        std::make_shared<RewardSquare>(),
        std::make_shared<RewardSquare>(),
        std::make_shared<RewardSquare>(),
        std::make_shared<RewardSquare>(),
        std::make_shared<RewardSquare>(),
        std::make_shared<RewardSquare>(),
        std::make_shared<RewardSquare>(),
        std::make_shared<RewardSquare>(),
        std::make_shared<RewardSquare>(),
        std::make_shared<RewardSquare>(),
        std::make_shared<RewardSquare>(),
        std::make_shared<RewardSquare>(),
        std::make_shared<RewardSquare>(),
        std::make_shared<RewardSquare>(),
        std::make_shared<RewardSquare>()};

};