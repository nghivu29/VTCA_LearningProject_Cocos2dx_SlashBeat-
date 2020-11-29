#include "InfiniteParallaxNode.h"

USING_NS_CC;

class PointObject : public Ref // Dựng 1 lớp PointObject
{
public:

	// Các hàm inline thiết lập, và lấy về các thuộc tính
	inline void setRation(Point ratio) { _ratio = ratio; }
	inline void setOffset(Point offset) { _offset = offset; }
	inline void setChild(Node *var) { _child = var; }
	inline Point getOffset() const { return _offset; }
	inline Node* getChild() const { return _child; }

private:
	Point _ratio; // Tỉ lệ
	Point _offset; // Độ lệch
	Node* _child; // Node con
};

InfiniteParallaxNode* InfiniteParallaxNode::create()
{
	// Tạo mới 1 đối tượng InfiniteParallaxNode*
	InfiniteParallaxNode* node = new InfiniteParallaxNode();
	if (node) {
		node->autorelease();
	}
	else {
		delete node;
		node = 0;
	}
	return node;
}

void InfiniteParallaxNode::updatePosition()
{
	float safeOffset = -10;

	Size visibleSize = Director::getInstance()->getVisibleSize();
	// 1. Duyệt các con của chuỗi parallax

	for (int i = 0; i < _children.size(); i++)
	{
		auto node = _children.at(i); // Node i
		// 2. Kiểm tra node đó có ra ngoài màn hình ko, convertToWorldSpace bạn tham khảo tại đây http://www.cocos2d-x.org/wiki/Coordinate_System.
		if (convertToWorldSpace(node->getPosition()).x + node->getContentSize().width*node->getScaleX() < safeOffset)
			// 3. Tìm PointObject tương ứng với node hiện tại
			for (int j = 0; j < _parallaxArray->num; j++)
			{
				auto po = (PointObject*)_parallaxArray->arr[j];
				// Nếu có thì tăng thêm độ lệch ra thêm 1 màn hình, tức xuất hiện lại thêm lần nữa
				if (po->getChild() == node)
					po->setOffset(po->getOffset() +
						Point(visibleSize.width + node->getContentSize().width*node->getScaleX(), 0));
			}
	}
}
