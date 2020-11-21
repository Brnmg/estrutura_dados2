import tweepy

# Informações do usuário
chave_consumidor = '@TEstrutura'
senha_consumidor = 'TrabEstrutura1'
token_acesso = ''
token_acesso_segredo = ''


# Autenticação da conta
autenticacao = tweepy.OAuthHandler(chave_consumidor, senha_consumidor)
autenticacao.set_access_token(token_acesso, token_acesso_segredo)

# Login
twitter = tweepy.API(autenticacao)

# Busca do termo
busca = twitter.search(q='Covid')

for tweet in busca:
    print(f'Tweet: {tweet.text}')