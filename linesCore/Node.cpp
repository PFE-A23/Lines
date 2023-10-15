#include "IGraphicsEngine.h"
#include "Node.h"
#include "Primitive.h"
#include "drwDrawingContext.h"

GLuint Node::NextId = 1;

Node::Node() : Position(0,0)
{
	Id = NextId++;
	ThePrimitive = 0;
	IsHidden = false;
	m_engine = new OpenGLGraphicsEngine();
}


Node::~Node()
{
	delete m_engine;
}


void Node::Draw( drwDrawingContext & context )
{
	if( ThePrimitive && !IsHidden )
	{
		if( context.m_isPicking )
			m_engine->pushName(Id);

		m_engine->pushMatrix();
		
		//glTranslate( Position );

		ThePrimitive->Draw( context );
		
		m_engine->popMatrix();
		
		if( context.m_isPicking )
			m_engine->popName();
	}
}

